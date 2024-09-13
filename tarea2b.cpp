int main() {
    pylist l1;          // P.1
    cout << l1 << endl; // []
    
    l1.append(3);       // P.2
    cout << l1 << endl; // [3]

    l1.append('A');
    l1.append(true);
    l1.append(3.0012);
    cout << l1 << endl; // [3,A,true,3.0012]
    
    pylist l2(1, 2.1, 'A', 'B');    // P.3
    cout << l2 << endl;             // [1,2.1,A,B]

    // P.4 (Una lista dentro de otra)
    l1.append(l2);
    cout << l1 << endl; // [3,A,true,3.0012,[1,2.1,A,B]]

    cout << len(l1) << endl; // 5
    cout << len(l2) << endl; // 4

    // P.5
    cout << l1[1] << endl; // A
    cout << l1[4] << endl; // [1,2.1,A,B,C++]

    // P.6
    l1[0] = 'X';
    cout << l1 << endl; // [X,A,true,3.0012,[1,2.1,A,B]]

    // P.7
    cout << (l1[1] == 'A') << endl; // 1 (verdadero)
    cout << (l1[3] == 3.0) << endl; // 0 (falso)
}