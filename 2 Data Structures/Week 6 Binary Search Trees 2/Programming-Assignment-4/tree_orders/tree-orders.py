# python3

import sys, threading
sys.setrecursionlimit(10**6) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size

class TreeOrders:
  def read(self):
    self.n = int(sys.stdin.readline())
    self.key = [0 for i in range(self.n)]
    self.left = [0 for i in range(self.n)]
    self.right = [0 for i in range(self.n)]
    for i in range(self.n):
      [a, b, c] = map(int, sys.stdin.readline().split())
      self.key[i] = a
      self.left[i] = b
      self.right[i] = c

  def inOrder(self):
    self.result = []
    # Finish the implementation
    # You may need to add a new recursive method to do that
    def inOrderTraversal(i, result):
        if self.left[i] != -1:
            inOrderTraversal(self.left[i], result)
        result.append(self.key[i])
        if self.right[i] != -1:
            inOrderTraversal(self.right[i], result)
    inOrderTraversal(0, self.result)
                
    return self.result

  def preOrder(self):
    self.result = []
    # Finish the implementation
    # You may need to add a new recursive method to do that
    def preOrderTraversal(i, result):
        result.append(self.key[i])
        if self.left[i] != -1:
            preOrderTraversal(self.left[i], result)        
        if self.right[i] != -1:
            preOrderTraversal(self.right[i], result)
    preOrderTraversal(0, self.result)
                
    return self.result

  def postOrder(self):
    self.result = []
    # Finish the implementation
    # You may need to add a new recursive method to do that
    def postOrderTraversal(i, result):
        if self.left[i] != -1:
            postOrderTraversal(self.left[i], result)        
        if self.right[i] != -1:
            postOrderTraversal(self.right[i], result)
        result.append(self.key[i])
    postOrderTraversal(0, self.result)
                
    return self.result

def main():
	tree = TreeOrders()
	tree.read()
	print(" ".join(str(x) for x in tree.inOrder()))
	print(" ".join(str(x) for x in tree.preOrder()))
	print(" ".join(str(x) for x in tree.postOrder()))

threading.Thread(target=main).start()
