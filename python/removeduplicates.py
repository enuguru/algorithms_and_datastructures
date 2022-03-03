s='I felt was happy but I was not happy,so I made others happy'
def remove_duplicates(s):
    my_list=[word for word in s.split(' ')]
    print(sorted(list(set(my_list))))

remove_duplicates(s)
