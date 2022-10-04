from turtle import *
import random

tin = Turtle()
screen = Screen()

# for finding angle 360/n  n=no of sides

colours = ["blue","medium spring green","lime","firebrick","purple","dark slate blue","gold","red","sea green	","spring green"]

def draw_shapes(num_of_sides):
    for n in range(num_of_sides):
        angle = 360 /num_of_sides
        tin.forward(100)
        tin.right(angle)


for i in range(3,10):
    tin.color(random.choice(colours))
    draw_shapes(i)

screen.exitonclick()