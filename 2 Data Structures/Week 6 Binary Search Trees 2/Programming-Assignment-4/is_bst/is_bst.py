#!/usr/bin/python3

import sys, threading

sys.setrecursionlimit(10**7) # max depth of recursion
threading.stack_size(2**25)  # new thread will get stack of such size

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

def IsBinarySearchTree(tree):
  # Implement correct algorithm here
  treevec = tree.inOrder()
  for i in range(1, len(treevec)):
      if treevec[i] < treevec[i-1]:
          return False
  
  return True

def main():
  tree = TreeOrders()
  tree.read()
  if IsBinarySearchTree(tree):
    print("CORRECT")
  else:
    print("INCORRECT")

threading.Thread(target=main).start()
