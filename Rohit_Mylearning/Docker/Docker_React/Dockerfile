FROM node:14-alpine

RUN mkdir -p /home/app

WORKDIR /home/app

#This will create new app i.e. my-first-react-app
RUN npx create-react-app my-first-react-app

#Set work directory as my-first-react-app
WORKDIR /home/app/my-first-react-app

#Execute the command at /home/app/my-first-react-app
CMD ["npm", "start"]
