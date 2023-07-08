def myAtoi(self, s: str) -> int:
        j= []
        sint=""
        sig=""
        k=0
        flag=True
        fd=True
        fs=True

        for i in s:
            j.append(i)
        for i in range(len(j)):
            if j[i]==' ' and fd==True and fs==True:
                continue
            # elif j[i]=='0' and fd==True :
            #     continue
            elif j[i]=='0'  :
                sint+="0"
                fd=False
            elif j[i]=="-" and flag==True and fd==True:
                flag=False
                fs=False
                sig+="-"
            elif j[i]=="+" and flag==True:
                flag=False
                sig+="+"
                fs=False
            elif j[i].isalpha() :
                break
            elif j[i].isnumeric():
                sint+=j[i]
                fd=False
            else:
                break
        if sig=="-" and sint!="":
            k= 0 - (int(sint))
            print(k)


        if (sint!="" and sig=="+" )or (sint!="" and sig==""):   
            k=int(sint)
            print(k)
        if k<=-(2**31):
            k=-(2**31) 
        elif k>=(2**31) :
            k=(2**31) -(1)
        print(sint," " ,k)
        if sint=="":
            return 0
        else:
            return int(k)
s ="1223"
num  = myAtoi(s)
print(num)