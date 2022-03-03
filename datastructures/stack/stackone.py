
# You can use Lists as Stacks in Python
stack = [10,9,8,7,6,5]
# Original contents of the stack
print "Original Contents of the Stack"
print stack
# Appending to a list is the same as pushing to a stack
stack.append(1)
stack.append(2)
# In the two steps above we push 1 and 2 onto the stack
print "After pushing 1 and 2 onto the stack it looks like:"
print stack

# Now we explore the pop operation
poppedValue = stack.pop()

# Display the popped value
print "Popped Value:"
print poppedValue

# Now display what the stack looks like:
print "After the pop operation the stack looks like:"
print stack

# Now we explore the pop operation again
poppedValue = stack.pop()

# Display the popped value
print "Again, we pop a value from the top of the stack. Popped Value:"
print poppedValue

# Now display what the stack looks like:
print "After the second pop operation the stack looks like:"
print stack
