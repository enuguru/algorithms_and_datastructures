

# Deques from collections are convenient to use as Queues
# It is not efficient to use lists because they are efficient for reading/appending/popping from the end
# But they are not so efficient for dequeing from the beginning
from collections import deque
queue = deque(["London","Paris","New York","Delhi"])
print("The Original Queue:")
print(queue)

# Now we also queue a few more cities
queue.append("Mumbai")
queue.append("Kolkata")
# Now display the queue after en-queueing these
print(queue)
# You will observe that Mumbai and Kolkata have been en-queued at the end of the queue

# Now let us start to De-que element from this queue
dequedElement1 = queue.popleft()
dequedElement2 = queue.popleft()
# Let us display the Dequeued Elements. 
# Given that a Queue is a First In First Out (FIFO) data structure the de-queued elements will be London and Paris
print("Two cities were de-queued")
print("First Dequeued city:")
print(dequedElement1)
print("First Dequeued city:")
print(dequedElement2)

# You will notice how the first two cities have been removed from the Queue, in FIFO order
print("Current state of the queue after dequeing two cities:")
print(queue)
