FROM node:lts-alpine AS build

WORKDIR /app

RUN npm i bun

COPY package.json bun.lock ./

RUN bun install --production

COPY . .

RUN bun run build

FROM nginx:stable-alpine

COPY --from=build /app/dist /usr/share/nginx/html

COPY nginx.conf /etc/nginx/conf.d/default.conf

EXPOSE 80