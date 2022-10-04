def rake_garden(garden):
    s = garden.split(" ")
    for i in range(0,len(s)):
        if(s[i] == 'gravel' or  s[i] == 'rock'):
            continue
        else:
            s[i] = 'gravel'
    return " ".join(s)
