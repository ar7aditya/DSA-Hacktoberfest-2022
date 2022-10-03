def count_simleys(arr):
    c = 0
    for i in range(len(arr)):
        if len(arr[i]) == 2:
            if(arr[i] == ":)" or arr[i] == ":D" or arr[i] == ";)" or arr[i] == ";D"):
                c += 1
        elif(len(arr[i]) == 3):
            if(arr[i] == ":~)" or arr[i] == ":~D" or arr[i] == ";~)" or arr[i] == ";~D" or arr[i] == ":-)" or arr[i] == ":-D" or arr[i] == ";-)" or arr[i] == ";-D"):
                c += 1
    return c
