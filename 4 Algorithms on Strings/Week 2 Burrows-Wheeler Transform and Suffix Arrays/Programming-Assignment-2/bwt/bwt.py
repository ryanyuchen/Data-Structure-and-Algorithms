# python3
import sys

def BWT(text):
    result = ""
    n = len(text)
    m = [""] * n
    newtext = text + text
    
    for i in range(n):
        m[i] = newtext[i:i + n]
    m = sorted(m, key=str.lower)
    
    for i in range(n):
        result += m[i][-1]

    return result

if __name__ == '__main__':
    text = sys.stdin.readline().strip()
    print(BWT(text))