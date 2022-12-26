-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 19, 2022 at 10:00 AM
-- Server version: 10.4.25-MariaDB
-- PHP Version: 8.0.23

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `at160419-atwl08`
--

-- --------------------------------------------------------

--
-- Table structure for table `categories`
--

CREATE TABLE `categories` (
  `id` int(11) NOT NULL,
  `name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `categories`
--

INSERT INTO `categories` (`id`, `name`) VALUES
(1, 'Iphone'),
(2, 'OPPO'),
(4, 'LG'),
(5, 'HTC'),
(6, 'SamSung');

-- --------------------------------------------------------

--
-- Table structure for table `classes`
--

CREATE TABLE `classes` (
  `ID` varchar(6) NOT NULL,
  `CLASSNAME` varchar(50) NOT NULL,
  `NUMOFSTUDENTS` int(11) NOT NULL,
  `CLASSDESCRIPTION` varchar(250) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `classes`
--

INSERT INTO `classes` (`ID`, `CLASSNAME`, `NUMOFSTUDENTS`, `CLASSDESCRIPTION`) VALUES
('ML01', 'lop 01', 2, 'mo ta 1'),
('ML02', 'lop 02', 3, 'mo ta 2');

-- --------------------------------------------------------

--
-- Table structure for table `hoso`
--

CREATE TABLE `hoso` (
  `MAHS` varchar(8) NOT NULL,
  `HOTEN` varchar(50) NOT NULL,
  `NGAYSINH` date NOT NULL,
  `DIACHI` varchar(150) NOT NULL,
  `LOP` varchar(6) NOT NULL,
  `DIEMTOAN` float NOT NULL,
  `DIEMLY` float NOT NULL,
  `DIEMHOA` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `hoso`
--

INSERT INTO `hoso` (`MAHS`, `HOTEN`, `NGAYSINH`, `DIACHI`, `LOP`, `DIEMTOAN`, `DIEMLY`, `DIEMHOA`) VALUES
('2', '2', '0000-00-00', '2', '2', 2, 2, 2),
('MS02', 'Hiếu Joyce', '2022-11-08', 'Dia chi 1', 'AT16D', 10, 9.5, 9.8);

-- --------------------------------------------------------

--
-- Table structure for table `lop`
--

CREATE TABLE `lop` (
  `MALOP` varchar(6) NOT NULL,
  `TENLOP` varchar(50) NOT NULL,
  `KHOAHOC` int(11) NOT NULL,
  `GVCN` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `lop`
--

INSERT INTO `lop` (`MALOP`, `TENLOP`, `KHOAHOC`, `GVCN`) VALUES
('AT1603', 'AT16C', 16, 'Nguyễn Văn C'),
('AT1604', 'AT16D', 16, 'Nguyễn Văn A');

-- --------------------------------------------------------

--
-- Table structure for table `products`
--

CREATE TABLE `products` (
  `id` int(11) NOT NULL,
  `name` varchar(100) NOT NULL,
  `price` int(11) NOT NULL,
  `count` int(11) NOT NULL,
  `image` varchar(100) NOT NULL,
  `dec` varchar(500) NOT NULL,
  `categoriesId` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `products`
--

INSERT INTO `products` (`id`, `name`, `price`, `count`, `image`, `dec`, `categoriesId`) VALUES
(1, 'Iphone 4', 14000000, 14, 'apple.png', 'mota1', 1),
(6, 'OPPO 2', 4000000, 5, 'sumsung.png', '<p>abc <strong>Mo ta </strong><i><strong>oppo</strong></i></p>', 2),
(7, 'OPPO 3', 4000000, 51, 'sumsung.png', '<h2>mo ta <i>123</i></h2>', 2);

-- --------------------------------------------------------

--
-- Table structure for table `students`
--

CREATE TABLE `students` (
  `ID` varchar(6) NOT NULL,
  `STUDENTNAME` varchar(20) NOT NULL,
  `STUDENTGENDER` varchar(20) NOT NULL,
  `STUDENTADDRESS` varchar(50) NOT NULL,
  `CLASSID` varchar(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `students`
--

INSERT INTO `students` (`ID`, `STUDENTNAME`, `STUDENTGENDER`, `STUDENTADDRESS`, `CLASSID`) VALUES
('MS01', 'name1', 'nam', 'diachi1', 'ML01'),
('MS02', 'name2', 'nu', 'diachi2', 'ML01'),
('MS03', 'name3', 'nam', 'diachi3', 'ML02'),
('MS04', 'name4', 'nam', 'diachi4', 'ML02'),
('MS05', 'name5', 'nu', 'diachi5', 'ML02');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `username` varchar(200) NOT NULL,
  `password` varchar(300) NOT NULL,
  `image` varchar(50) NOT NULL,
  `address` varchar(100) NOT NULL,
  `gender` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `username`, `password`, `image`, `address`, `gender`) VALUES
(1, 'hieujoyce', '123456', 'apple.png', 'Ha Nam', 'Nam'),
(2, 'hieujoyce02', '123456', 'apple.png', 'Thanh Hoa', 'Nam');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `categories`
--
ALTER TABLE `categories`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `classes`
--
ALTER TABLE `classes`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `hoso`
--
ALTER TABLE `hoso`
  ADD PRIMARY KEY (`MAHS`);

--
-- Indexes for table `lop`
--
ALTER TABLE `lop`
  ADD PRIMARY KEY (`MALOP`);

--
-- Indexes for table `products`
--
ALTER TABLE `products`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `students`
--
ALTER TABLE `students`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `categories`
--
ALTER TABLE `categories`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `products`
--
ALTER TABLE `products`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
