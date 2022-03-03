import pandas as pd
df = pd.DataFrame({'foo': ['one', 'one', 'one', 'two', 'two', 'two'],
                   'bar': ['A', 'B', 'A', 'A', 'B', 'C'],
                   'baz': [1, 2, 3, 4, 5, 6]})

print(df)

dfone = df.pivot_table(index='foo',columns='bar',values='baz',fill_value=0)
print(dfone)
