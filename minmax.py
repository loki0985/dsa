import math

def minimax(depth, index, isMax, scores, maxDepth):

    if depth == maxDepth:
        return scores[index]

    if isMax:
        return max(
            minimax(depth+1, index*2, False, scores, maxDepth),
            minimax(depth+1, index*2+1, False, scores, maxDepth)
        )
    else:
        return min(
            minimax(depth+1, index*2, True, scores, maxDepth),
            minimax(depth+1, index*2+1, True, scores, maxDepth)
        )


scores = [3,5,2,9,12,5,23,23]

depth = int(math.log2(len(scores)))

print("Optimal value:", minimax(0,0,True,scores,depth))