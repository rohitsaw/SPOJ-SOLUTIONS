import heapq
 
t = int(input())
 
for ts in range(1,t+1):
    n,r = map(int, input().split())
    
    G = {i:[] for i in range(n)}
    indegree = {i:0 for i in range(n)}
    
    for _ in range(r):
        r1,r2 = map(int, input().split())
        
        G[r2].append(r1)
        indegree[r1] += 1
        
    h = []
    for k,v in indegree.items():
        if v==0:
            heapq.heappush(h,(k,1))
    
    to = []
    while len(h):
        temp = heapq.heappop(h)
        to.append(temp)
        for each in G[temp[0]]:
            indegree[each] -= 1
            if indegree[each]==0:
                heapq.heappush(h,(each,temp[1]+1))
    if len(to)==n:
        to.sort(key=lambda x: (x[1],x[0]) )
        print("Scenario #"+str(ts)+":")
        for each in to:
            print(each[1], each[0])
    else:
        print("not possible") 

