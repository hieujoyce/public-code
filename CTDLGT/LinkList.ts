class NodePointer<T> {
    private data: T;
    private prev: NodePointer<T>;
    private next: NodePointer<T>;
    constructor(data: T, prev?: NodePointer<T>, next?: NodePointer<T>) {
        this.data = data;
        this.prev = prev ? prev : null;
        this.next = next ? next : null;
    }

    public getData(): T {
        return this.data;
    }

    public setData(data: T): void {
        this.data = data;
    }

    public getPrev(): NodePointer<T> {
        return this.prev;
    }

    public setPrev(prev: NodePointer<T>): void {
        this.prev = prev;
    }

    public getNext(): NodePointer<T> {
        return this.next;
    }

    public setNext(next: NodePointer<T>): void {
        this.next = next;
    }

    public toString(): string {
        return `${this.data}`;
    }
}

class LinkList<T> {
    private length: number;
    private tail: NodePointer<T>;
    private head: NodePointer<T>;

    constructor() {
        this.length = 0;
        this.tail = this.head = null;
    }

    public clear(): void {
        let currentNode = this.head;
        while (currentNode !== null) {
            let nextNode = currentNode.getNext();
            currentNode.setData(null);
            currentNode.setNext(null);
            currentNode.setPrev(null);
            currentNode = nextNode;
        }
        this.head = this.tail = null;
        this.length = 0;
    }

    public size(): number {
        return this.length;
    }

    public isEmpty(): boolean {
        return this.length == 0;
    }

    public addLast(el: T): void {
        let newNode = new NodePointer(el);
        if (this.isEmpty()) {
            this.head = this.tail = newNode;
        } else {
            this.tail.setNext(newNode);
            newNode.setPrev(this.tail);
            this.tail = newNode;
        }
        this.length++;
    }

    public add(el: T): void {
        this.addLast(el);
    }

    public peekLast(): T {
        if (this.isEmpty()) throw new Error("Link List is Empty");
        return this.tail.getData();
    }

    public peekFirst(): T {
        if (this.isEmpty()) throw new Error("Link List is Empty");
        return this.head.getData();
    }

    public removeLast(): T {
        if (this.isEmpty()) throw new Error("Link List is Empty");
        let data = this.tail.getData();
        this.length--;
        if (this.isEmpty()) {
            this.head = this.tail = null;
        } else {
            this.tail = this.tail.getPrev();
            this.tail.setNext(null);
        }
        return data;
    }
    public removeFirst(): T {
        if (this.isEmpty()) throw new Error("Link List is Empty");
        let data = this.head.getData();
        this.length--;
        if (this.isEmpty()) {
            this.head = this.tail = null;
        } else {
            this.head = this.head.getNext();
            this.head.setPrev(null);
        }
        return data;
    }

    public addFirst(el: T): void {
        let newNode = new NodePointer(el);
        if (this.isEmpty()) {
            this.tail = this.head = newNode;
        } else {
            this.head.setPrev(newNode);
            newNode.setNext(this.head);
            this.head = newNode;
        }
        this.length++;
    }

    public toString(): string {
        let str = "[";
        let currentNode = this.head;
        while (currentNode !== null) {
            str += currentNode.toString();
            if (currentNode.getNext() !== null) str += ", ";
            currentNode = currentNode.getNext();
        }
        str += "]";
        return str;
    }

    public remove(rmNode: NodePointer<T>): void {
        if (rmNode.getPrev() === null) {
            this.removeFirst();
            return;
        } else if (rmNode.getNext() === null) {
            this.removeLast();
            return;
        }
        rmNode.getPrev().setNext(rmNode.getNext());
        rmNode.getNext().setPrev(rmNode.getPrev());
        this.length--;
    }

    public getNodeIndex(index: number): NodePointer<T> {
        if (index < 0 || index >= this.length) throw new Error("");
        let currentNode = this.head;
        for (let i = 1; i <= index; i++) {
            currentNode = currentNode.getNext();
        }
        return currentNode;
    }

    public removeAt(index: number): void {
        this.remove(this.getNodeIndex(index));
    }

    public indexOf(data: T): number {
        let currentNode = this.head;
        let index = 0;
        while (index < this.length) {
            if (currentNode.getData() === data) {
                return index;
            }
            currentNode = currentNode.getNext();
            index++;
        }
        return -1;
    }

    public contains(data: T): boolean {
        let currentNode = this.head;
        let index = 0;
        while (index < this.length) {
            if (currentNode.getData() === data) {
                return true;
            }
            currentNode = currentNode.getNext();
            index++;
        }
        return false;
    }
}

(function test() {
    let a = new NodePointer(2);
    console.log(a.toString());
    let b = new LinkList();
    console.log(b.isEmpty());
    //console.log(b.peekLast());
    for (let i = 1; i <= 10; i++) {
        b.addFirst(i);
    }
    console.log("length: " + b.size());
    // for (let i = 1; i <= 10; i++) {
    //     console.log(b.removeFirst());
    // }
    // console.log(b.toString());
    // console.log("length: " + b.size());
    console.log(b.contains(3));
    console.log(b.contains(11));
    console.log(b.indexOf(2));
    console.log(b.toString());
})();
