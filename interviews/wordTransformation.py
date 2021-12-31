from collections import defaultdict

# if wordList = ["hog", "cog"], then shortest distance is "hot"->"hog"->"cog" = 3
def solution(beginWord, endWord, wordList):
    # if edit distance is 1, then we can connect an edge from word to word
    # then just use on the starting word
    adjList = defaultdict(list)
    n = len(wordList)
    for i in range(n):
        word = wordList[i]
        numDiffBegin = 0
        numDiffEnd = 0
        for j in range(len(word)):
            if word[j] != beginWord[j]:
                numDiffBegin += 1
            if word[j] != endWord[j]:
                numDiffEnd += 1
        if numDiffBegin <= 1:
            adjList[beginWord].append(word)
        if numDiffEnd <= 1:
            adjList[word].append(endWord)
    
    for i in range(n):
        for j in range(n):
            if i != j:
                word1 = wordList[i]
                word2 = wordList[j]
                numDiff = 0
                for k in range(len(word1)):
                    if word1[k] != word2[k]:
                        numDiff += 1
                if numDiff <= 1:
                    adjList[word1].append(word2)
    
    return bfs(beginWord, endWord, adjList)
    
def bfs(beginWord, endWord, adjList):
    queue = []
    queue.append(beginWord)
    
    visited = {}
    for key, val in adjList.items():
        visited[key] = False
    
    visited[beginWord] = True
    
    ans = 1
    while queue:
        for i in range(len(queue)):
            front = queue.pop(0)
            if front == endWord:
                return ans
            for i in range(len(adjList[front])):
                word = adjList[front][i]
                if word in visited and not visited[word]:
                    queue.append(adjList[front][i])
                    visited[word] = True
        ans += 1
    
    return 0