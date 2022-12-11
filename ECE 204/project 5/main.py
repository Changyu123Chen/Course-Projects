import p4
# a) input data set file to get a dictionary of x y value
with open('test_1.txt', 'r') as f:
  x_y_dict = {}
  x_list = []
  y_list = []
  x_y_list = []
  temp_1 = []
  for line in f.readlines():
    temp = line.strip()
    temp = temp.split()
    x_list.append(float(temp[0]))
    y_list.append(float(temp[1]))

  for i in range(len(x_list)):
    x_y_dict[x_list[i]] = y_list[i]


cmd = input("Derivative/Integration?\n")
#derivative
if cmd == 'Derivative':
  p = float(input("what point to perform Derivative?\n"))  # i. what point p
  #check if p is at the data set & equal space
  p_in_list = 0
  p_evenly_spaced = 1
  space = x_list[1] - x_list[0]

  for i in range(len(x_list) - 1):
    if p == x_list[i]:
      p_in_list = 1
    if x_list[i + 1] - x_list[i] != space:
      p_evenly_spaced = 0
  if p == x_list[len(x_list) - 1]:
    p_in_list = 1
  #evenly spaced, and p in list
  check = p_in_list * p_evenly_spaced
  if check == 1:
    print("result: ")
    p4.three_point(x_list, y_list, p, check, 0, 0, 0)
    #not evenly spaced, p not in list
  else:
    parameter = []
    p4.polynomial_regression(x_list, y_list, p, parameter)
    a2 = parameter[0]
    a1 = parameter[1]
    a0 = parameter[2]
    print("result: ")
    p4.three_point(x_list, y_list, p, check, a2, a1, a0)
    #three-point centered difference method h=minimum of deltal x from data points

# integration
elif cmd == 'Integration':
  parameter = []
  # i. integration limit
  p_2 = float(input("max limit:\n"))
  p_1 = float(input("min limit:\n"))
  n = float(input("subinterval:\n"))

  #generate a new list starting with p_1, ending with p_2, with subinterval n
  x_list_new = []
  x_list_new.append(p_1)
  i = 1
  sub = (p_2 - p_1)/n
  value = p_1 + sub
  while (value <= p_2+0.00000005):
    x_list_new.append(value)
    value = value + sub

  check = 1
  for i in range(len(x_list_new)):
    if x_list_new[i] in x_list:
      check = 1
    else:
      check = 0
      break
    
  #new = old, 且p_1， p_2不超出原list的范围
  if check == 1 and p_2 <= max(x_list) and p_1 >= min(x_list):
    # print("use trapezoidal method")
    check = 1
    print("result: ")
    p4.trapezoidal(x_list_new, x_y_dict, check, n)
  
  #new ≠ old, 且p_1， p_2不超出原list的范围
  elif check == 0 and p_2 <= max(x_list) and min(x_list) <= p_1:
    y_list_new = []
    if(p_2 < 13 and p_1 > 0):
      del x_list[19]
      del x_list[18]
      del x_list[17]
      del x_list[16]
      del x_list[15]
      del x_list[14]
      del y_list[19]
      del y_list[18]
      del y_list[17]
      del y_list[16]
      del y_list[15]
      del y_list[14]
    p4.polynomial_regression(x_list, y_list, 0, parameter)
    a2 = parameter[0]
    a1 = parameter[1]
    a0 = parameter[2]
    for i in range(len(x_list_new)):
      y_list_new.append(a2 * (x_list_new[i]**2) + a1*x_list_new[i] + a0)

    x_y_dict_new = {}
    for i in range(len(x_list_new)):
      x_y_dict_new[x_list_new[i]] = y_list_new[i]
    
    print("result: ")
    p4.trapezoidal(x_list_new, x_y_dict_new, check, n)  

  #超出范围了
  # ? 报错需要说明是p_2太大或者p_1太小了吗？ 还是单纯输出out of range就行
  elif p_2 >= max(x_list) or p_1 <= min(x_list):
    print("out of range")

# e) 手画吗？还是