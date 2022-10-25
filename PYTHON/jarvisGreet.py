import speech_recognition as sr
import pyttsx3 as tts

def Recognize():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source)
        print("Say Something")
        audio = r.listen(source)
        try:
            voiceData = r.recognize_google(audio)
            return voiceData
        except sr.UnknownValueError:
            print("Sorry, didn't understand")
        except sr.RequestError:
            print("Speech Service Down")
 
# data = Recognize()

# print(f"Voice Data : {data}")

engine = tts.init("sapi5")
engine.setProperty("rate",194)
voice = engine.getProperty("voices")
engine.setProperty("voice",voice[1].id)

def speak(text):
    engine.say(text)
    engine.runAndWait()
    engine.stop()

JarvisGreets = ["hello jarvis", "hey jarvis", "hey jarv", "hello jarv", "hello darkness"]

voiceData = Recognize()

voiceDataList = voiceData.split(" ")


print(f"Voice Data : {voiceData}")

def JarvisGreet(state="alone", name=""):
    if state.lower() == "simple":
        speak("Hello Sir!")
    if state.lower() == "alone":
        speak("Hello Sir! How can i help?")
    if state.lower() == "greet" and name.lower() == "":
        speak(f"Hello {name}. Nice to meet you!")


for greeting in JarvisGreets:
    voiceData = voiceData.lower()
    if greeting == voiceData:
        JarvisGreet("alone")
        break
    if greeting in voiceData:
        JarvisGreet("simple")
        break


JarvisHello = ["say hello to", "greet"]

for hello in JarvisHello:
    if hello in voiceData:
        voiceData = voiceData.lower()
        tempList = hello.split(" ")
        tempListLength = len(tempList)
        nameInit = voiceDataList.index(tempList[0])
        nameIndex = nameInit + tempListLength
        name = voiceDataList[nameIndex]
        JarvisGreet("greet", name)