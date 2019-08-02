const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const outputDir = path.join(__dirname, 'build/');

const isProd = process.env.NODE_ENV === 'production';
const webpack = require('webpack');

module.exports = {
  entry: './src/index.js',
  mode: isProd ? 'production' : 'development',
  output: {
    path: outputDir,
    filename: 'Index.js'
  },
  module: {
    rules: [
      {
        test: /\.css$/,
        use: ['style-loader', 'css-loader']
      },
      // {
      //   test: /\.(js|jsx)$/,
      //   exclude: /node_modules/,
      //   use: ['babel-loader']
      // }
    ]
  },  
  resolve: {
    extensions: ['*', '.js', '.jsx']
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: 'src/index.html',
      inject: false
    }),
    new webpack.HotModuleReplacementPlugin()
  ],
  devServer: {
    compress: true,
    contentBase: outputDir,
    port: process.env.PORT || 8000,
    historyApiFallback: true,
    hot: true
  }
};
