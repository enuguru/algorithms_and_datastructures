import pandas as pd
df = pd.DataFrame({'foo': ['one', 'one', 'one', 'two', 'two', 'two'],
                   'bar': ['A', 'B', 'C', 'A', 'B', 'C'],
                   'baz': [1, 2, 3, 4, 5, 6]})

print(df)

dfone = df.pivot(index='foo',columns='bar',values='baz')
print(dfone)
