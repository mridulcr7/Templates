
let task = prompt("What would you like to do").toLowerCase();
const todo = [];
while (task !== "quit") {
    if (task === "new") {
        let item = prompt("Enter new to do");
        todo.push(item);
        console.log(`${item} added to your list`);
    }
    else if (task === "list") {
        console.log("*/");
        let k = 0;
        for (let x of todo) {
            console.log(`${k}. ${x}`);
            k++;
        }
        console.log("*/");
    }
    else if (task === "delete") {
        let idx = prompt("Enter index of the item to be deleted");
        console.log(`${todo[idx]} removed from your list`);
        todo.splice(idx, 1);
    }
    task = prompt("What would you like to do").toLowerCase();
}
console.log("OK You Quit The App");
