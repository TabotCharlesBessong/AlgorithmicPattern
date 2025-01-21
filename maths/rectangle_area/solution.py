def computeArea(A, B, C, D, E, F, G, H):
  # Areas of both rectangles
  area1 = (C - A) * (D - B)
  area2 = (G - E) * (H - F)
  
  # Overlap dimensions
  overlap_width = max(0, min(C, G) - max(A, E))
  overlap_height = max(0, min(D, H) - max(B, F))
  overlap_area = overlap_width * overlap_height
  
  # Total area
  return area1 + area2 - overlap_area

overlap_area = computeArea(-3,0,3,4,0,-1,9,2)
print("The tatal overlap area is: ", overlap_area)
