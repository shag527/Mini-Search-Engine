with open('raw.tar\\raw.txt','r',encoding="UTF-8") as f:
    with open("DSdataset_fin.txt", "a",encoding="UTF-8") as dataset:
        for num,line in enumerate(f):
            txt=line.split('|||')[1]
            sample=str(num)+'\t'+txt
            dataset.write(sample)
            print(num,txt)
            if(num==10000):
                break
