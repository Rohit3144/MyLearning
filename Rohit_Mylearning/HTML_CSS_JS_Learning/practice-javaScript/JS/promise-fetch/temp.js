function existing(data, newdata) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      try {
        data.push(...newdata);
        resolve(data);
      } catch {
        reject(error);
      }
    }, 2000);
  });
}
arr = [11, 22, 33];
existing(arr, [1, 2, 3, 'rk', 'rk'])
  .then((result) => {
    console.log("Data added successfully. Updated array: ", result);
  })
  .catch((error) => {
    console.log("Error in adding data ", error);
  });
