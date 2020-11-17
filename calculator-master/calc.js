
screen = document.getElementById('input').value;
let status=0;


function getinput(i){
    if(i==='='){
        document.getElementById('input').value=eval(document.getElementById('input').value) 
    }
    else if(i=='+' || i=='-' || i=='*' || i=='/'){
        if(status==0){
            document.getElementById('input').value += i ;
            status=1;
        }
    
    
    }
    else if(i=='b'){
        var value = document.getElementById("input").value;
       document.getElementById("input").value = value.substr(0, value.length - 1);

        
    }
    else if(i=='c'){
        document.getElementById('input').value='';
        
    }
    
    else{
        document.getElementById('input').value += i ;
        status=0;
    }

}