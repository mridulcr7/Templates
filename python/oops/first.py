
class Student:
    Course="Btech"
    def __init__(self,age,subject):
        Student.age=age
        Student.subject=subject

    def printit(self):
        print(f"age is {Student.age} and subject is {Student.subject}")


mridul=Student(22,"DS")
mridul.Course="ba"
print(mridul.Course)
mridul.printit()
print(Student.Course)

arth=Student(21,"OS")
print(arth.Course)

