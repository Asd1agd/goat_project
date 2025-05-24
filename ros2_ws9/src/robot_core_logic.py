table1 = []
table2 = []
table3 = []

table1_ = []
table2_ = []
table3_ = []

table_list = ["t1","t2","t3"]

table_dict = {"table1":[["t1",[12,30,11],1],["t1",[12,30,11],1]],"table2":[["t2",[12,30,11],2],["t2",[12,30,11],2]],"table3":[["t3",[12,30,11],3],["t3",[12,30,11],3]]}


cooking_time = 10 # sec
order_wait = 30 # sec

kitchen = []
wetter_robot = []
tables = 3
order_id = 0
wetter_capacity = 5 # orders at a time

for table in table_dict:
    if abs(table_dict[table][1][-1][-1] - kitchen[-1][-11]) == 1:    
        kitchen.append(table_dict[table][1][-1])
        del table_dict[table][1][-1]

while capacity_overflow == 0 and timer < order_wait:
    for order in kitchen:
        order_time = order[1][0]*24*60 + order[1][1]*60 + order[1][1]
        if (order_time - ctime()) > cooking_time and len(wetter_robot) <= wetter_capacity:
            wetter_robot.append(order)
            kitchen.remove(order)
        if len(wetter_robot) > wetter_capacity:
            capacity_overflow = 1

for order in wetter_robot:
    for table_order in table_dict[list(table_dict.keys())[table_no]][0]:
        if table_order[-1] == order[-1]:    # order id is same
            wetter_robot.remove(order)
            table_dict[list(table_dict.keys())[table_no]][0].remove(table_order)

while len(wetter_robot) == 0:
    if len(kitchen) > 0:
        naigate_to_kichen()
        while capacity_overflow == 0 and timer < order_wait:
            for order in kitchen:
                order_time = order[1][0]*24*60 + order[1][1]*60 + order[1][1]
                if (order_time - ctime()) > cooking_time and len(wetter_robot) <= wetter_capacity:
                    wetter_robot.append(order)
                    kitchen.remove(order)
                if len(wetter_robot) > wetter_capacity:
                    capacity_overflow = 1
    if timer > order_wait and len(wetter_robot)==0:
         naigate_to_home()
    while len(wetter_robot) > 0:
        table_no = table_list.index(wetter_robot[0][0])
        move_to(table_no)
        for order in wetter_robot:
            for table_order in table_dict[list(table_dict.keys())[table_no]][0]:
                if table_order[-1] == order[-1]:    # order id is same
                    wetter_robot.remove(order)
                    table_dict[list(table_dict.keys())[table_no]][0].remove(table_order)

    if timer_stedy > stedy_state and len(wetter_robot)==0:
         naigate_to_home()
         
    if order_canceled:  # in seperate threde
        id_no = get_id_no()
        for table in table_list:
            for order in table_dict[table][1]:
                if id_no == order[-1]:
                    table_dict[table][1].remove(order)
            for order in table_dict[table][0]:
                if id_no == order[-1]:
                    table_dict[table][0].remove(order)
        for order in kitchen:
            if id_no == order[-1]:
                kitchen.remove(order)
        for order in wetter_robot:
            if id_no == order[-1]:
                wetter_robot.remove(order)



table_dict = {"table1":[[[1,2,3],[1,3,4]],[[1,4,3],[1,3,8]]],"table2":[[3],[4]],"table3":[[5],[6]]}
table_dict["table1"][0].remove([1,2,3])
print(table_dict)

# for table in table_dict:
# print(table_dict[0])

tb = 3
tc = 4

cc = tb
print(cc)
tb = 8

print(cc)