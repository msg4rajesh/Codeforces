import os

def main():
    s = raw_input("Input round name = ")
    if os.path.exists(s):
        op = raw_input("Folder exists. Continue?")
        if (op == "N") or (op == "n"):
            return
    else:
        os.system("mkdir %s" % s)
    t = input("Total problems number = ")
    for i in range(t):
        os.system("cp template.cpp %s/%c.cpp" % (s, chr(ord('A') + i)))

if __name__ == "__main__":
    main()
