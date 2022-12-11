import matplotlib.pyplot as plt
import numpy as np
import p4
# get the points
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

parameter = []
p4.polynomial_regression(x_list, y_list, 1, parameter)
# print(parameter)
a2 = parameter[0]
a1 = parameter[1]
a0 = parameter[2]

x = np.arange(0, 19, 1)
y = a2*(x**2) + a1*x + a0
#分别存放所有点的横坐标和纵坐标，一一对应

#创建图并命名
plt.figure('original vs regression')
ax = plt.gca()
#设置x轴、y轴名称
ax.set_xlabel('x')
ax.set_ylabel('y')

#画连线图，以x_list中的值为横坐标，以y_list中的值为纵坐标
#参数c指定连线的颜色，linewidth指定连线宽度，alpha指定连线的透明度
ax.plot(x_list, y_list, color='b', linewidth=2, alpha=1, label = "original")
ax.plot(x, y, color='r', linewidth=2, alpha=1, label = "regression")
plt.legend()
plt.show()