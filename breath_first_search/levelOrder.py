from collections import deque

class TreeNode:
  def __init__(self, val=0,left=None,right=None):
    self.val = val
    self.left = left
    self.right = right
 
def levelOrder(root):
  if not root:
    return []
  q = deque()   
  
  q.append(root)
  
  big_list = []
  
  while len(q):
    size = len(q)
    small_list = []
    for _ in range(size):
      node = q.popleft()
      small_list.append(node.val)
      
      if node.left:
        q.append(node.left)
      if node.right:
        q.append(node.right)
        
    big_list.append(small_list)
    
  return big_list   # [[3], [9, 20], [15, 7]]
    
if __name__ == '__main__':
  # [3,9,20,null,null,15,7]
  head = TreeNode(3)
  head.left = TreeNode(9,None,None)
  head.right = TreeNode(20,TreeNode(15,None,None),TreeNode(7,None,None))
  
  print(levelOrder(head))  # Expected output: [[3], [9, 20], [15, 7]]