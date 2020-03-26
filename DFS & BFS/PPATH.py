from collections import defaultdict
import queue
 
G = defaultdict(list)
primes = set()
 
 
def is_prime(i):
    import math
    for j in range(2,int(math.sqrt(i)+1)):
        if i%j==0:
            return False
    return True
 
def create_primes():
    for i in range(1000, 9999+1):
        if is_prime(i):
            primes.add(i)
        
def make_graph():
    
    for each in primes:
        d = str(each)
        d4 = d[0]
        d3 = d[1]
        d2 = d[2]
        d1 = d[3]
        
        for i in range(0,9+1):
            temp = str(i)
            
            if int(temp) != 0:
                newd = int(temp+d3+d2+d1)
                if newd in primes and newd != each:
                    G[each].append(newd)
                    #G[newd].append(each)
                
            newd = int(d4+temp+d2+d1)
            if newd in primes and newd != each:
                G[each].append(newd)
                #G[newd].append(each)
                
            newd = int(d4+d3+temp+d1)
            if newd in primes and newd != each:
                G[each].append(newd)
                #G[newd].append(each)
                
            newd = int(d4+d3+d2+temp)
            if newd in primes and newd != each:
                G[each].append(newd)
                #G[newd].append(each)
            
            
def BFS(a,b):
    
    sp = {}
    sp[a] = 0
    
    q.put(a)
    seen = set()
    
    while not q.empty():
        k = q.get()
        seen.add(k)
        
        for each in G[k]:
            if each not in seen:
                q.put(each)
                seen.add(each)
                sp[each] = sp[k] + 1
    
    if b in sp.keys():
        return sp[b]
    else:
        return "Impossible"
                
 
    
 
    
# driving program
            
t = int(input())
 
create_primes()
make_graph()
q = queue.Queue(maxsize = len(G.keys()))
 
for _ in range(t):
    a,b = map(int, input().split())
    
    ans = BFS(a,b)
    
    print(ans) 
