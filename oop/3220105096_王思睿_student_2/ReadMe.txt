我的测试数据在src文件夹中
可以任意修改数据
Alice   Math       90        ART         85             
Bob     Math       88        English     90        Science     87        Art         85       
Charlie Computer   92        English     89        Science     91        Geography   87       
David   Math       85        English     82        Science     88        Music       90       
Emily   Science    91        English     86        History     89        
Frank   Math       87        Art         84        Science     90              
Grace   Math       89        English     87        Science     92        History     89       
Henry   
Ivy     Computer   86        English     83        Science     90        History     88       
Jack    Math       90        English     85        Science     87        Art         89       

不需要输入学生的数量以及每个学生有几节课
只要在final.txt中改好就可以用make生成文件
在build文件夹中使用  cmake ..
然后使用  make
最后可执行文件在  bin文件夹中
这是最后的结果

Alice     	Math      90	ART       85	average_score 87.50  
Bob       	Math      88	English   90	Science   87	Art       85	average_score 87.50  
Charlie   	Computer  92	English   89	Science   91	Geography 87	average_score 89.75  
David     	Math      85	English   82	Science   88	Music     90	average_score 86.25  
Emily     	Science   91	English   86	History   89	average_score 88.67  
Frank     	Math      87	Art       84	Science   90	average_score 87.00  
Grace     	Math      89	English   87	Science   92	History   89	average_score 89.25  
Henry     	average_score 0.00   
Ivy       	Computer  86	English   83	Science   90	History   88	average_score 86.75  
Jack      	Math      90	 English   85	Science   87	Art       89	average_score 87.75  
           ART       Art       Computer  English   Geography History   Math      Music     Science   
average    85.00     86.00     89.00     86.00     87.00     88.67     88.17     90.00     89.50     
max        85        89        92        90        87        89        90        90        92        
min        85        84        86        82        87        88        85        90        87        
