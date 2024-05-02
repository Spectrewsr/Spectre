在这个程序中，有5种房间，分别是lobby，normal room， monster room， one way room， princess room。
one way room是一种单向通道房间，

房间的门都是随机生成的，但是保证了东门与西门相对，不会出现方向不对，比如东门进入北门这种情况。
其他房间都保证了从各个房间的门是相对的，并且会记录路径，
比如从A的东门进入B的西门，从B的西门回来时一定是A的东门。达到了记录路径的目的。
例子如下：
Welcome to the lobby room
There are 2 exits :north and south
go north
Welcome to the princess room
There are 3 exits :west,east and south
go south
Welcome to the lobby room
There are 2 exits :north and south

其中one way room是一种奇特的房间，从房间A的west door进入one way room的east door，但是从one way room
的east door出来却不是房间A，因此是一种单向房间。
例子如下：
Welcome to the lobby room
There are 4 exits :west,east,north and south      
go east
Welcome to the one_way room
There are 4 exits :west,east,north and south      
go west
Welcome to the normal room
There are 3 exits :west,east and south

与公主的对话：
Princess: thank you for saving me!
You: let's get back to lobby
Princess: now which door shall we go?


下面是一些通关示例：
Welcome to the lobby room
There are 2 exits :north and south
go north
Welcome to the princess room
There are 3 exits :west,east and south
Princess: thank you for saving me!
You: let's get back to lobby
Princess: now which door shall we go?

go south
Welcome to the lobby room
There are 2 exits :north and south
go south
You have saved the princess! You Win
You have played this game, would you like to play it again? Y/N
Y
Welcome to the lobby room
There are 2 exits :west and north
go west
Welcome to the normal room
There are 2 exits :east and south
go south
Welcome to the normal room
There are 2 exits :west and north
go west
Welcome to the normal room
There are 3 exits :west,east and north
go west
Welcome to the normal room
There are 3 exits :west,east and north
go west
You meet a Moster! Game over
You have played this game, would you like to play it again? Y/N
Y  
Welcome to the lobby room
There are 3 exits :west,east and south



Welcome to the lobby room
There are 2 exits :west and north
go west
Welcome to the normal room
There are 2 exits :east and south
go south
Welcome to the normal room
There are 2 exits :west and north
go west
Welcome to the normal room
There are 3 exits :west,east and north
go west
Welcome to the normal room
There are 3 exits :west,east and north
go west
You meet a Moster! Game over
You have played this game, would you like to play it again? Y/N
Y  

最后是一个经过很长一段路径成功的例子
Welcome to the lobby room
There are 3 exits :west,north and south
go west
Welcome to the normal room
There are 2 exits :east and south
go south
Welcome to the normal room
There are 3 exits :west,north and south
go west
Welcome to the normal room
There are 4 exits :west,east,north and south      
go west
Welcome to the one_way room
There are 3 exits :west,east and north
go west
Welcome to the normal room
There are 3 exits :west,east and north
go west
Welcome to the princess room
There are 4 exits :west,east,north and south    
Princess: thank you for saving me!
You: let's get back to lobby
Princess: now which door shall we go?

go east
Welcome to the normal room
There are 3 exits :west,east and north
go east
Welcome to the one_way room
There are 3 exits :west,east and north
go east
Welcome to the normal room
There are 3 exits :west,north and south
go north
Welcome to the lobby room
There are 3 exits :west,north and south
You have saved the princess! You Win
You have played this game, would you like to play it again? Y/N




