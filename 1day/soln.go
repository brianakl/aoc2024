package main

import "fmt"
import "os"
import "log"
import "bufio"
import "strings"
import "strconv"


func part(A *[]int, lo int, hi int) int {

    i := lo
    pivot := (*A)[hi]

    for j := lo; j < hi; j++ {

        if (*A)[j] <= pivot {

            x := (*A)[i]
            (*A)[i] = (*A)[j]
            (*A)[j] = x
            i++

        }
    }

    x := (*A)[i]
    (*A)[i] = (*A)[hi]
    (*A)[hi] = x

    return i
}


func quicksort(A *[]int, lo int, hi int) {

    if lo >= hi || lo < 0 {
        return 
    }

    p := part(A, lo, hi)

    quicksort(A, lo, p-1)
    quicksort(A, p+1, hi)
}

func main() {


    file, err := os.Open("input.txt")
    if err != nil{
        log.Fatal(err)
    }

    defer file.Close()

    r1 := []int{}
    r2 := []int{}

    scanner := bufio.NewScanner(file)

    for scanner.Scan() {

        line := scanner.Text()
        a := strings.Split(line, " ")

        x, err := strconv.Atoi(a[0])
        if err != nil{
            log.Fatal(err)
        }
        r1 = append(r1, x)

        y, err := strconv.Atoi(a[3])
        if err != nil{
            log.Fatal(err)
        }
        r2 = append(r2, y)

    }

    quicksort(&r1, 0, len(r1)-1)
    quicksort(&r2, 0, len(r2)-1)

    sum := 0

    for i := 0; i < len(r1); i++ {

        d := r1[i] - r2[i]
        if d < 0 {
            d *= -1
        }

        sum += d

    }

    fmt.Println(sum)



}
