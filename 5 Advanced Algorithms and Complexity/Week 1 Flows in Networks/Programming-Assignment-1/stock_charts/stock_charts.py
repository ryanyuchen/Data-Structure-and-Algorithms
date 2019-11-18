# python3
import queue

class StockCharts:
    def read_data(self):
        n, k = map(int, input().split())
        stock_data = [list(map(int, input().split())) for i in range(n)]
        return stock_data

    def write_response(self, result):
        print(result)

    def min_charts(self, stock_data):
        # Replace this incorrect greedy algorithm with an
        # algorithm that correctly finds the minimum number
        # of charts on which we can put all the stock data
        # without intersections of graphs on one chart.
        n = len(stock_data)
        k = len(stock_data[0])
        adj_matrix = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if all([x < y for x, y in zip(stock_data[i], stock_data[j])]):
                    adj_matrix[i][j] = 1
        matching = [-1] * n
        busy_right = [False] * n
        def BFS():
            visitedNode = set()
            q = queue.Queue()
            q.put((1, None))
            visitedNode.add((1, None))
            path = []
            parent = dict()
            while not q.empty():
                currentNode = q.get()
                if 1 == currentNode[0]:
                    for i in range(n):
                        if -1 == matching[i]:
                            visitedNode.add((2, i))
                            parent[(2, i)] = currentNode
                            q.put((2, i))
                elif 2 == currentNode[0]:
                    i = currentNode[1]
                    for j in range(n):
                        if 1 == adj_matrix[i][j] and j != matching[i] and not (3, j) in visitedNode:
                            visitedNode.add((3, j))
                            parent[(3, j)] = currentNode
                            q.put((3, j))
                elif 3 == currentNode[0]:
                    j = currentNode[1]
                    if not busy_right[j]:
                        prevNode = currentNode
                        currentNode = (4, j)
                        while True:
                            path.insert(0, (prevNode, currentNode))
                            if 1 == prevNode[0]:
                                break
                            currentNode = prevNode
                            prevNode = parent[currentNode]
                        for e in path:
                            if 2 == e[0][0]:
                                matching[e[0][1]] = e[1][1]
                            elif 3 == e[0][0] and 4 == e[1][0]:
                                busy_right[e[1][1]] = True
                        return True
                    else:
                        for i in range(n):
                            if j == matching[i] and not (2, i) in visitedNode:
                                visitedNode.add((2, i))
                                parent[(2, i)] = currentNode
                                q.put((2, i))
            return False
        
        while BFS():
            continue
        
        return len([0 for i in matching if -1 == i])

    def solve(self):
        stock_data = self.read_data()
        result = self.min_charts(stock_data)
        self.write_response(result)

if __name__ == '__main__':
    stock_charts = StockCharts()
    stock_charts.solve()
