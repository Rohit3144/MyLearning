function existing(data, newdata) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      try {
        resolve(data.push(newdata));
      } catch {
        reject(error);
      }
    }, 2000);
  });
}
arr = [1, 2, 3, 4, 5];
existing(arr, 33)
  .then((result) => {
    console.log("Data added successfully ", result);
  })
  .catch((error) => {
    console.log("Error in adding data ", error);
  });
