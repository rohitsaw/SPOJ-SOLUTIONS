import Queue
from collections import defaultdict
 
def bfs(row,col):
    
    visited = [[0]*c for _ in range(r)]
    sp = defaultdict(int)
    q = Queue.Queue(maxsize=c*r)
    q.put((row,col))
    visited[row][col] = 1
    sp[(row,col)] = 0
    
    dx = [1,-1,0,0]
    dy = [0,0,1,-1]
    
    while not q.empty():
        temp = q.get()
        i = temp[0]
        j = temp[1]
        
        for k in range(4):
            ti = i + dx[k]
            tj = j + dy[k]
            
            if (ti<0 or ti>=r) or (tj<0 or tj>=c) or visited[ti][tj] or mat[ti][tj]=="#":
                continue
            else:
                #print ti,tj
                visited[ti][tj] = True
                q.put((ti,tj))
                sp[(ti,tj)] = sp[(i,j)] + 1
        
        
            
    key = max(sp, key=lambda x: sp[x])
    #print key,sp[key]
    return key,sp[key]
 
t = int(raw_input())
 
for _ in range(t):
    c,r = map(int, raw_input().split())
    mat = []
    
    
    for _ in range(r):
        row = list(raw_input())
        mat.append(row)
        
    flag = False
    for row in range(r):
        for col in range(c):
            if (mat[row][col]=="."):
                key,value = bfs(row,col) 
                flag = True
                break
        if flag:
            break
    k,v = bfs(key[0],key[1])
    print "Maximum rope length is "+str(v)+"." 
