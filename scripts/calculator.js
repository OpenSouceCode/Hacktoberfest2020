const display = document.getElementById('display');
const history = document.getElementById('history');
const btn = document.querySelectorAll('.btn');

let a = '';
let b = '';
let operator = '';
let answer = '';

btn.forEach(button => {
    button.addEventListener('click', (e) => setParams(e))
});

const setParams = (e) =>{
    let input = e.target.value;

    if (e.target.matches('button.btn.num')) {

        if (operator == '') {
            if (a.length < 12) {
                a += input;
            }
            render(a);
            if (answer == '') {renderHistory(a)};
        } else {
            if (b.length < 12) {
                b += input;
            }
            render(b);
            }
        }

    if (e.target.matches('button.btn.delete')) {
        operator == '' ? (a = a.toString().slice(0, -1), render(a)) : (b = b.toString().slice(0, -1), render(b));
    }

    if (e.target.matches('button.btn.dot')) {
        if (operator == '') {
            a.includes('.') ? '' : a += input;
            render(a);
        } else {
            b.includes('.') ? '' : b += input;
            render(b);
        }
    }

    if (e.target.matches('button.btn.sign')) {
        b == '' ? a = -a : b = -b;
        b == '' ? render(a) : render(b);
    }

    if (e.target.matches('button.btn.operator')) {
        if (operator != '') {
            operate();
            operator = input;
        } else {
            operator = input;
        }
    }

}

const render = (x) => {
    emptyDisplay();
    const para = document.createElement('p');
    para.innerText = x;
    x == "Cannot divide by 0" || para.innerHTML.length <= 15 ? para.innerHTML : para.innerHTML = para.innerHTML.substring(0,15);
    display.appendChild(para);
}

const renderHistory = (x) => {
    const para = document.createElement('p');
    para.innerText = x;
    history.appendChild(para);
}

const emptyDisplay = () => {
    display.innerHTML = '';
}

const operate = () => {

    if (a != '' && b != 0 && operator != '/') {renderHistory(operator)}
    if (a != '' && b != 0) {renderHistory(b)};
    
    if (b == '') {
        render(a);
    } else {
        a = parseFloat(a);
        b = parseFloat(b);
        switch(operator) {
            case '/':
                if (b == 0) {
                    answer = "Cannot divide by 0";
                    render(answer);
                    answer = '';
                    break;
                } else {
                    answer = a/b;
                    render(answer);
                }
                break;
            case '*':
                answer = a*b;
                render(answer);
                break;
            case '+':
                answer = a+b;
                render(answer);
                break;
            case '-':
                answer = a-b;
                render(answer);
                break;
        }
        
        b = '';
        answer == '' ? '' :  a = answer;
    }
};

document.getElementById('clear').addEventListener('click', function(){
    history.innerHTML = '';
    display.innerHTML = '';
    a = '';
    b = '';
    operator = '';
    answer = '';
});

document.getElementById('equals').addEventListener('click', operate);
