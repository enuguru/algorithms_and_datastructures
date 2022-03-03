import itertools
def groupstate(person):
    return person['state']
person=[
        {'name':'Badri',
         'city':'Bangalore',
         'state':'Karnataka'
        },

        {'name':'Karthik',
         'city':'Bangalore South',
         'state':'Karnataka'
        },

        {'name':'rishab',
         'city':'Ranchi',
         'state':'Jharkand'
        },

        {'name':'kushal',
         'city':'Ranchi',
         'state':'Jharkand'
        }
      ]

person_group=itertools.groupby(person,groupstate)
for i,f in person_group:
    print(i)
    for b in f:
        print(b)
    

