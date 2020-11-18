var numSquares = 9;
var colors = generateRandomColors(numSquares);
var squares = document.querySelectorAll(".square");
var pickedColor = pickColor();
var colorDisplay = document.getElementById("colorDisplay");
var messageDisplay = document.querySelector("#message");
var h1 = document.querySelector("h1");
var resetButton = document.querySelector("#reset");
var easyBtn = document.querySelector("#easyBtn");
var mediumBtn = document.querySelector("#mediumBtn");
var hardBtn = document.querySelector("#hardBtn");

easyBtn.addEventListener("click", function(){
  hardBtn.classList.remove("selected");
  mediumBtn.classList.remove("selected");
  easyBtn.classList.add("selected");
  numSquares = 3;
  colors = generateRandomColors(numSquares);
  pickedColor = pickColor();
  colorDisplay.textContent = pickedColor;
  for(var i = 0 ; i < squares.length; i++)
  {
    if(colors[i])
    {
      squares[i].style.backgroundColor = colors[i];
    }
    else
    {
      squares[i].style.display = "none";
    }
  }
});

mediumBtn.addEventListener("click", function(){
  hardBtn.classList.remove("selected");
  mediumBtn.classList.add("selected");
  easyBtn.classList.remove("selected");
  numSquares = 6;
  colors = generateRandomColors(numSquares);
  pickedColor = pickColor();
  colorDisplay.textContent = pickedColor;
  for(var i = 0 ; i < squares.length; i++)
  {
    if(colors[i])
    {
      squares[i].style.backgroundColor = colors[i];
      squares[i].style.display = "block";
    }
    else
    {
      squares[i].style.display = "none";
    }
  }
});

hardBtn.addEventListener("click", function(){
  easyBtn.classList.remove("selected");
  mediumBtn.classList.remove("selected");
  hardBtn.classList.add("selected");
  numSquares = 9;
  colors = generateRandomColors(numSquares);
  pickedColor = pickColor();
  colorDisplay.textContent = pickedColor;
  for(var i = 0 ; i < squares.length; i++)
  {
    squares[i].style.backgroundColor = colors[i];
    squares[i].style.display = "block";
  }
});

resetButton.addEventListener("click", function(){
  // generate new colors
  colors = generateRandomColors(numSquares);
  // pick a randomcolor from array
  pickedColor = pickColor();
  // change display color to match picked color
  colorDisplay.textContent = pickedColor;
  this.textContent = "New Colors";
  // change display message back to empty
  messageDisplay.textContent = "";
  // change colors of squares
  for(var i = 0 ; i < squares.length ; i ++)
  {
    // add new colors to squares
    squares[i].style.backgroundColor = colors[i];
  }
  h1.style.backgroundColor = "steelblue";
});

colorDisplay.textContent = pickedColor;

for(var i = 0 ; i < squares.length ; i ++)
{
  // add initial colors to squares
  squares[i].style.backgroundColor = colors[i];

  // add click listeners to the squares
  squares[i].addEventListener("click", function() {
    // grab color of picked color
    var clickedColor = this.style.backgroundColor;
    // compare color of picked color
    if(clickedColor === pickedColor)
    {
      messageDisplay.textContent = "Correct!";
      resetButton.textContent = "Play Again?";
      changeColors(clickedColor);
      h1.style.backgroundColor = clickedColor;
    }
    else
    {
      this.style.backgroundColor = "#232323";
      messageDisplay.textContent = "Try Again";
    }
  });
}

function changeColors(color)
{
    // loop through all squares
    for(var i=0 ; i < squares.length ; i++)
    {
      // chnage each color to match given color
      squares[i].style.backgroundColor = color;
    }
}

function pickColor()
{
  var random = Math.floor(Math.random() * colors.length);
  return colors[random];
}

function generateRandomColors(num)
{
  // make an array
  var arr = []
  // repeat num times
  for(var i = 0 ; i < num ; i++)
  {
    // get random colors and push into array
    arr.push(randomColors());
  }
  // return that array
  return arr;
}

function randomColors()
{
  // pick a "red" from 0 - 255
  var r = Math.floor(Math.random() * 256);
  // pick a "green" from 0 - 255
  var g = Math.floor(Math.random() * 256);
  // pick a "blue" from 0 - 255
  var b = Math.floor(Math.random() * 256);
  // return rgb() value
  return "rgb(" + r + ", " + g + ", " + b + ")" ;
}
