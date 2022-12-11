#!/usr/bin/env python3
import numpy as np
from numpy.linalg import inv
# function:
    # three point centered
def three_point(x_list, y_list, p, check, a2, a1, a0):
  if check == 1:
    index = x_list.index(p)
    h_1 = x_list[index - 1] - p #-1 p = 7
    h_2 = x_list[index + 1] - p # 1 = - 7
    f_p1 = y_list[index +1]
    f_p = y_list[index]
    f_m1 = y_list[index - 1]
    p_der = (f_p1 - 2*f_p + f_m1)*0/(h_1**2) + (f_p1 - f_m1)/(2*h_2)


  else:
    h = abs(p - x_list[0])
    for i in range(len(x_list)):
      if abs(p-x_list[i]) < h:
        h = abs(p-x_list[i]) # p = 7.6 h = 0.4
    p_der = ((a2*((p+h)**2) + a1*(p+h) + a0)-((a2*(p-h)**2) + a1*(p-h) + a0))/(2 * h) #p = 7.6
  print(p_der)
  return

    # regression
def polynomial_regression(x_list, y_list, p, parameter):
  n = len(x_list)
  a_4 = 0
  a_3 = 0
  a_2 = 0
  a_1 = 0
  b_2 = 0
  b_1 = 0
  b_0 = 0
  for i in range(n):
    a_4 = a_4 + x_list[i]**4
    a_3 = a_3 + x_list[i]**3
    a_2 = a_2 + x_list[i]**2
    a_1 = a_1 + x_list[i]
    b_2 = b_2 + x_list[i] * x_list[i] * y_list[i]
    b_1 = b_1 + x_list[i] * y_list[i]
    b_0 = b_0 + y_list[i]
  
  A = np.array([[a_4, a_3, a_2],[a_3, a_2, a_1], [a_2, a_1, n]])
  A = inv(A)
  B = np.array([[b_2], [b_1], [b_0]])
  A = np.dot(A, B)
  
  a2 = A[0][0]
  a1 = A[1][0]
  a0 = A[2][0]
  parameter.append(a2)
  parameter.append(a1)
  parameter.append(a0)
  return

    # trapezoidal
def trapezoidal(x_list, x_y_dict, check, n):
  h = float((max(x_list) - min(x_list))/n)
  sum = 0.0
  f = 0.0
  for i in range(1, len(x_list)-1):
    sum = sum + x_y_dict[x_list[i]]
  f = float((h/2.0)*(x_y_dict[max(x_list)] + x_y_dict[min(x_list)]+ 2.0*sum))
  print(f)
  return









