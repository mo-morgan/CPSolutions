class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        graph = []
        for i in range(0, n):
            graph.append([i+1])
        k = len(queries)
        ans = []
        for i in range(k):
            u = queries[i][0]
            v = queries[i][1]
            graph[u].append(v)
            ans.append(self.shortest_distance(graph, 0, n-1))

        return ans

    def shortest_distance(self, graph, start, target):
        q = deque([(start, 0)])
        visited = [False] * len(graph)
        visited[start] = True

        while q:
            node, dist = q.popleft()

            if node == target:
                return dist

            for nei in graph[node]:
                if not visited[nei]:
                    visited[nei] = True
                    q.append((nei, dist + 1))

        return -1