import time
import threading
import math

# Create threads
t1 = threading.Thread(target=timer_stedy)
t2 = threading.Thread(target=print_letters)


table1 = []
table2 = []
table3 = []

table1_ = []
table2_ = []
table3_ = []

table_list = ["t1","t2","t3"]
order_canceled = [4,1]
table_cords = [[-5.5, -1.0, 0.0],[-3.4, 0.0, 0.0],[-0.5, 1.0, 0.0]]
kitchen_cords = [3.8, -8.0, 0.0]
home_cords = [-3.221095085144043, -4.4982757568359375, 1.9229348]

table_dict = {"table1":[["t1",[12,30,11],1],["t1",[12,30,11],1]],"table2":[["t2",[12,30,11],2],["t2",[12,30,11],2]],"table3":[["t3",[12,30,11],3],["t3",[12,30,11],3]]}


cooking_time = 10 # sec
order_wait = 30 # sec
stedy_state = 2*60

kitchen = []
wetter_robot = []
tables = 3
order_id = 0
wetter_capacity = 5 # orders at a time

timer_stedy_val = 0
kitchen_timer_val = 0
lock = threading.Lock()

def ctime():
    current_time = time.time()
    local_time = time.localtime(current_time)

    hr = local_time.tm_hour
    min = local_time.tm_min
    sec = local_time.tm_sec

    C_time = hr*24*60 + min*60 + sec

    return C_time



def timer_stedy():
    global timer_stedy_val
    p_time = ctime()
    while True:
        bot_px = get_x()
        bot_py = get_y()
        time.sleep(1)
        bot_cx = get_x()
        bot_cy = get_y()
        if abs(math.dist((bot_px,bot_py),(bot_cx,bot_cy))) > 0.2:  # asumed meter
            p_time = ctime()

        with lock:
            timer_stedy_val = ctime() - p_time

def kitchen_timer():
    kitchen_cords = [0,0]
    pTime = ctime()
    global kitchen_timer_val
    while True:
        bot_px = get_x()
        bot_py = get_y()
        bot_cords = [bot_px,bot_py]
        if math.dist(bot_cords,kitchen_cords) > 5:
            pTime = ctime()
        kitchen_timer_val = ctime() - pTime

def cancel_order():
    while True:
        if len(order_canceled) > 0:  # in seperate threde
            id_no = order_canceled[0]
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

def move_to(cords):
    # send cords to navigater node i.e kitchen_cords = [3.8, -8.0, 0.0]
    # wait for the navigation complete responce frome navigator node
    pass

t1 = threading.Thread(target=timer_stedy)
t1.start()
t2 = threading.Thread(target=kitchen_timer)
t2.start()
t3 = threading.Thread(target=cancel_order)
t3.start()


def timer_stedy_value():
    with lock:
        timer_stedy_val2 = timer_stedy_val 
    return timer_stedy_val2

def kitchen_timer_value():
    with lock:
        kitchen_timer_val2 = kitchen_timer_val 
    return kitchen_timer_val2
        


for table in table_dict:
    if abs(table_dict[table][1][-1][-1] - kitchen[-1][-11]) == 1:    
        kitchen.append(table_dict[table][1][-1])
        del table_dict[table][1][-1]


while len(wetter_robot) == 0:
    if len(kitchen) > 0:
        move_to(kitchen_cords)
        while capacity_overflow == 0 and kitchen_timer_value() < order_wait:
            for order in kitchen:
                order_time = order[1][0]*24*60 + order[1][1]*60 + order[1][1]
                if (order_time - ctime()) > cooking_time and len(wetter_robot) <= wetter_capacity:
                    wetter_robot.append(order)
                    kitchen.remove(order)
                if len(wetter_robot) > wetter_capacity:
                    capacity_overflow = 1
    if kitchen_timer_value() > order_wait and len(wetter_robot)==0:
        move_to(home_cords)
    while len(wetter_robot) > 0:
        table_no = table_list.index(wetter_robot[0][0])
        move_to(table_cords[table_no])
        for order in wetter_robot:
            for table_order in table_dict[list(table_dict.keys())[table_no]][0]:
                if table_order[-1] == order[-1]:    # order id is same
                    wetter_robot.remove(order)
                    table_dict[list(table_dict.keys())[table_no]][0].remove(table_order)

    if timer_stedy_value() > stedy_state and len(wetter_robot)==0:
        move_to(home_cords)
         

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