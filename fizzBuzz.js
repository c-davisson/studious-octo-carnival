var fizzBuzz=function(A) {
    if(A%3===0 && A%5===0){
        return("Fizz Buzz");
    }
    else if(A%3===0){
        return("Fizz");
    }
    else if(A%5===0){
        return("Buzz");
    }
    else if(A%3!==0 && A%5!==0){
        return(A);
    };

};


