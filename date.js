//after refacturing

//get date
exports.getDate = function (){
  const today = new Date();

  const options = {
    weekday: "long",
    day: "numeric",
    month: "long"
  }

  return today.toLocaleDateString("en-US", options);

}

//get day
exports.getDay = function() {
  const today = new Date();

  const options = {
    weekday: "long"
  }

return today.toLocaleDateString("en-US", options);
}
//we can change let to const as we are not changing anything
