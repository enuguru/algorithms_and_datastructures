d={'Rahul':[67,76,39],'Sameer':[58,86,78],'Rakesh':[59,70,81]}
for row in zip(*([k]+(v) for k,v in sorted(d.items()))):
    print(zip(*row),sep='\t')
