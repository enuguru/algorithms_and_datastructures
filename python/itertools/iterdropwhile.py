
import itertools
def lt_2(n):
    if n<=2:
        return True
    else:
        return False

numbers=[1,2,2,3,2,6,10]
tw=itertools.takewhile(lt_2,numbers)
dw=itertools.dropwhile(lt_2,numbers)
print(list(tw))
print(list(dw))
