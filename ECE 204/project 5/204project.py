# a) input data set file to get a dictionary of x y value
with open("test_1.txt") as f:
	x_y_dict = {}
	x_list = []
	y_list = []
	x_y_list = []
	temp_1 = []
	for line in f.readlines(): #遍历file text1,读去name和key
		temp = line.strip()
		temp = temp.split()		
		x_list.append(float(temp[0]))
		y_list.append(float(temp[1]))
	for i in range(len(x_list)):
		x_y_dict[x_list[i]] = y_list[i]
	
	#print(x_y_dict)
#######################华丽分割线#######################################		
# b) derivative or integration
cmd = input("What you want to perform Derivative or Integration?\n")

# c)
if cmd == "Derivative": #derivative
	# i. what point p
	p = int(input("what point to perform Derivative?\n"))
	#check if p is at the data set & equal space
	p_in_list = 0
	p_even = 1
	space = x_list[1] - x_list[0]

	for i in range(len(x_list)-1):
		if i == x_list[i]:
			p_cond = 1
		#check if equal space
		if x_list[i+1] - x_list[i] != space:
			p_even = 0
	if i == x_list[len(x_list)-1]:
		p_cond = 1
	else: 
		p_cond = p_cond*1

	if p_cond * p_even == 1: #evenly spaced, and p in list
		#three point centered difference method
		index = x_list.index(p)
		h_1 = x_list[index-1] - p
		h_2 = x_list[index+1] - p
		p_der = (y_list[index+1]-2*y_list[index]+y_list[index-1])*p/(2*h_1*h_1) + (y_list[index+1]-y_list[index-1])/(2*abs(h_2))
        else:
                #polynomial regression
		print("待会再写")
		#three-point centered difference method h=minimum of deltal x from data points

	#show solution for p = 77; p = 18.5
        print(p_der)

elif(cmd == "Integration\n"):  #integration
	# i. integration limit
	p_2 = input("max limit\n")
	p_1 = input("min limit\n")
	n = input("subinterval\n")
	#generate new data set with the limits
	x_list_new = []
	x_list_new[0] = p_1
	i = 1
	while(p_1+n < p2):
		x_list_new[i].append(p_1+n)
		i = i + 1
	x_list_new[i] = p_2

	#if new == old trapezoidal method
	if x_list_new == x_list and p_2 < max(x_list) and min(x_list) < p_1:#不确定这个语法对不对
		print("use trapezoidal method")
	# iv. else if within range, new value != original polynomial regression->function->integration trapezoidal method Δx
	elif x_list_new != x_list and p_2 < max(x_list) and min(x_list) < p_1:
		print("polynomial regression")

		print("trapezoidal method")
	# v. else if out of range: message err
	elif p_2 > max(x_list) or p_1 < min(x_list):
		print("out of range")
	# solution for cases 

	#e) 是需要手画吗？









