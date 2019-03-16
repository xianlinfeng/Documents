import os
from multiprocessing import Process, current_process
# from multiprocessing import Process, current_process



# define a function as a task
def square(number):
    result = number * number
    # process_id = os.getpid()
    # print(f"Process ID: {process_id} ")

    process_name = current_process().name
    print(f"Process Name: {process_name}")

    print(f"The number {number} squares to {result} .")


# the main function
if __name__ == '__main__':
    processes = []
    numbers = [1, 2, 3, 4, 5, 6, 7, 5, 5, 6]

    for number in numbers:
        process = Process(target=square, args=(number,))
        processes.append(process)
        process.start()


# youtube:
# https://www.youtube.com/watch?v=RR4SoktDQAw&list=PL5tcWHG-UPH3SX16DI6EP1FlEibgxkg_6