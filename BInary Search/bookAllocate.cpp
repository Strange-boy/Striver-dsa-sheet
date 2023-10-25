#include <bits/stdc++.h>
using namespace std;

//predicate function 
int studentsAllocatedBooks(vector<int> &pages, int maxPages){
    int studentAllocated = 1;
    int pagesAllocated = 0;

    for(int page: pages){
        if(pagesAllocated + page <= maxPages){
            pagesAllocated += page;
        } else {
            studentAllocated += 1;
            pagesAllocated = page;
        }
    }

    return studentAllocated;
}

// Logic: find the range(pages) and Binary Search to find minPages
// Time complexity:O(log(sum - max + 1)) * O(pages)
int bookAllocation(vector<int> &pages,int books, int students){
    if(students > books) return -1;

    int start = -1;
    int end = 0, minPages = 0;
    

    //minimum pages -> max pages of books
    for(auto pageBook: pages) start = max(pageBook, start);

    //sum of all the books
    for(auto pageBook: pages) end += pageBook;

    while(start <= end){
        int mid = (start + end) / 2;

        int cntStudents = studentsAllocatedBooks(pages, mid);

        if(cntStudents > students){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return start;
}

// Logic: find the range(pages) and iterate to find minPages
// Time complexity:O(sum - max + 1) * O(pages)
int bruteBookAllocate(vector<int> &pages, int books, int students){
    if(students > books) return -1;

    int start = -1;
    int end = 0;

    //minimum pages -> max pages of books
    for(auto pageBook: pages) start = max(pageBook, start);

    //sum of all the books
    for(auto pageBook: pages) end += pageBook;

    for(int page = start; page <= end; page += 1){
        int cntStudents = studentsAllocatedBooks(pages,page);
        if(cntStudents == students){
            return page;
        }
    }

    //if the above condition doesn't satify
    return -1;
}

int main(){
    int books, students;
    cin >> books >> students;

    vector<int> pages(books);

    //enter the page of each book
    for(auto &page: pages) cin >> page;

    // int minPages = bruteBookAllocate(pages, books, students);
    int minPages = bookAllocation(pages, books, students);

    cout << minPages << '\n';
}