# python3
import sys

_END = '$'

def compress_recursive(tree, node):
    for (key, child_node) in tree[node].items():
        if key == "start":
            return
        if len(tree[child_node]) == 1:
            path_char = next(iter(tree[child_node]))
            
            if path_char != "start":
                grand_child_node = tree[child_node][path_char]
                tree[node][key + path_char] = grand_child_node
                del tree[node][key]
                del tree[child_node]
                compress_recursive(tree, grand_child_node)
                
        else:
            compress_recursive(tree, child_node)

def build_suffix_tree(text):
  """
  Build a suffix tree of the string text and return a list
  with all of the labels of its edges (the corresponding 
  substrings of the text) in any order.
  """
  result = []
  # Implement this function yourself
  tree = dict()
  tree[0] = {}
  index = 0
  
  for start in range(len(text)):
      word = text[start:]
      current_node = 0
      for char in word:
          if char in tree[current_node].keys():
              current_node = tree[current_node][char]
          else:
              index += 1
              new_node = index
              if char == _END:
                  tree[new_node] = {"start": start}
              else:
                  tree[new_node] = {}
                  tree[current_node][char] = new_node
                  current_node = new_node
  
  current_node = 0
  compress_recursive(tree, current_node)
  for node in tree:
      for c in tree[node]:
          if c != "start":
              result.append(c)
      
  return result


if __name__ == '__main__':
  text = sys.stdin.readline().strip()
  result = build_suffix_tree(text)
  print("\n".join(result))