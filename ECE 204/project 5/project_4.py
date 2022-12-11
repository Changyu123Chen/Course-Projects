#!/usr/bin/env python3
with open('test_1.txt','r') as f:
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

	print(x_y_dict)



cmd = input("what point to perform Derivative?\n")

if cmd == 'Derivative':
	p = float(input("what point to perform Derivative?\n"))
	# print(p)
	p_in_list = 0
	# p_cond = 0
	p_evenly_spaced = 1
	space = x_list[1] - x_list[0]

	for i in range(len(x_list)-1):
		if p == x_list[i]:
			p_in_list = 1
		if x_list[i+1] - x_list[i] != space:
			p_evenly_spaced = 0
			# break
	if p == x_list[len(x_list)-1]:
		p_in_list = 1
	if p_in_list * p_evenly_spaced == 1:
		index = x_list.index(p)
		h_1 = x_list[index-1] - p
		print(h_1)
		print(h_2)
		h_2 = x_list[index+1] - p
		p_der = (y_list[index+1]-2*y_list[index]+y_list[index-1])*p/(2*h_1*h_1) + (y_list[index+1]-y_list[index-1])/(2*abs(h_2))
		print(p_der)
	else:
		print("haoleiya")
elif cmd == 'Integration':
	p_2 = float(input("max limit:\n"))
	p_1 = float(input("min limit:\n"))
	n = float(input("subinterval:\n"))

	x_list_new = []
	x_list_new[0] = p_1
	i = 1
	while(p_1+n < p_2):
		x_list_new[i].append(p_1+n)
		i = i+1
		n = n * i
	x_list_new[i] = p_2

















