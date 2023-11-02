def findWords(board, words):
    trie = {}
    for word in words:
        node = trie
        for letter in word:
            if letter not in node:
                node[letter] = {}
            node = node[letter]
        node['$'] = word
    
    def search(node, x, y):
        letter = board[x][y]
        curr_node = node[letter]
        
        word_match = curr_node.pop('$', False)
        if word_match:
            results.append(word_match)
        
        board[x][y] = '#'
        for (dx, dy) in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < len(board) and 0 <= ny < len(board[0]) and board[nx][ny] in curr_node:
                search(curr_node, nx, ny)
        board[x][y] = letter
        
        if not curr_node:
            node.pop(letter)
    
    results = []
    for x in range(len(board)):
        for y in range(len(board[0])):
            if board[x][y] in trie:
                search(trie, x, y)
    return results

# Test
board = [
    ['o','a','a','n'],
    ['e','t','a','e'],
    ['i','h','k','r'],
    ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]
print(findWords(board, words))  # Output: ['oath', 'eat']
