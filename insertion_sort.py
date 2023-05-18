import sys

def insertion_sort():
    arr = sys.argv[1:]
    # [5,4,3,2,1]
    # while j=2 to j=a.length
    for idx in range(1,len(arr)):
        key = arr[idx]
        j = idx-1
        # insert a[idx] to a[0,....j-1]
        while j>=0 and arr[j]>key:
            arr[j+1] = arr[j]
            j=j-1
        arr[j+1]=key
    print(arr)



if __name__=="__main__":
    insertion_sort()